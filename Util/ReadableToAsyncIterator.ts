import {Readable} from 'node:stream';
import * as assert from 'node:assert';

type PromiseCallbackParameters<R> = Parameters<
  ConstructorParameters<typeof Promise<R>>[0]
>;
type PromiseResolve<R> = PromiseCallbackParameters<R>[0];
type PromiseReject<R> = PromiseCallbackParameters<R>[1];

export async function* getAsyncIteratorFromReadable<R>(readable: Readable) {
  let promiseResolve: PromiseResolve<void> | null = null;
  let promiseReject: PromiseReject<void> | null = null;
  let promise = new Promise<void>((resolve, reject) => {
    promiseResolve = resolve;
    promiseReject = reject;
  });
  let done = false;
  let chunks: R[] = [];

  readable.on('data', (chunk) => {
    chunks.push(chunk);
    assert.ok(promiseResolve);
    promiseResolve();

    promise = new Promise<void>((resolve, reject) => {
      promiseResolve = resolve;
      promiseReject = reject;
    });
  });

  readable.on('end', () => {
    done = true;
    assert.ok(promiseResolve);
    promiseResolve();
  });

  readable.on('error', (e) => {
    done = true;
    assert.ok(promiseReject);
    promiseReject(e);
  });

  while (!done) {
    await promise;
    yield* chunks;
    chunks = [];
  }
}
