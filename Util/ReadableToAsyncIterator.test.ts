import {describe, expect} from '@jest/globals';
import fs from 'fs';
import path from 'node:path';
import {getAsyncIteratorFromReadable} from './ReadableToAsyncIterator';

describe('Readable to AsyncIterator', () => {
  const filePath = path.resolve(__dirname, __filename);
  const fileContent = fs.readFileSync(filePath, {encoding: 'utf-8'});

  it('should convert Readable to AsyncIterator', async () => {
    const readable = fs.createReadStream(filePath, {encoding: 'utf-8'});
    const asyncIterator = getAsyncIteratorFromReadable<string>(readable);
    const chunks: string[] = [];
    for await (const chunk of asyncIterator) {
      chunks.push(chunk);
    }
    const fileContentReadByAsyncIterator = chunks.join('');

    expect(fileContentReadByAsyncIterator).toEqual(fileContent);
  });

  it('should support concurrent read', async () => {
    const readTask = async () => {
      const readable = fs.createReadStream(filePath, {encoding: 'utf-8'});
      const asyncIterator = getAsyncIteratorFromReadable<string>(readable);
      const chunks: string[] = [];
      for await (const chunk of asyncIterator) {
        chunks.push(chunk);
      }
      return chunks.join('');
    };

    const promises: Promise<string>[] = [];
    for (let i = 0; i < 10; i++) {
      promises.push(readTask());
    }

    const fileContentsReadByAsyncIterators = await Promise.all(promises);
    for (const fileContentReadByAsyncIterator of fileContentsReadByAsyncIterators) {
      expect(fileContentReadByAsyncIterator).toEqual(fileContent);
    }
  });
});
