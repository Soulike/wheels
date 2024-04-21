class UnionFindSet {
  /** @type {number[]} */
  #parent;
  /** @type {number} */
  #size;
  /** @type {number} */
  #setCount;

  /**
   * @param {number} size
   */
  constructor(size) {
    this.#parent = new Array(size);
    for (let i = 0; i < size; i++) {
      this.#parent[i] = i;
    }
    this.#size = size;
    this.#setCount = size;
  }

  getSize() {
    return this.#size;
  }

  getSetCount() {
    return this.#setCount;
  }

  /**
   * @param {number} element1
   * @param {number} element2
   * @returns {void}
   */
  union(element1, element2) {
    const root1 = this.#find(element1);
    const root2 = this.#find(element2);
    if (root1 !== root2) {
      this.#setCount--;
      this.#parent[root2] = root1;
    }
  }

  /**
   * @param {number} element1
   * @param {number} element2
   * @returns {boolean}
   */
  isInOneSet(element1, element2) {
    return this.#find(element1) === this.#find(element2);
  }

  /**
   * @param {number} element
   * @returns {number}
   */
  #find(element) {
    let currentMember = element;
    while (this.#parent[currentMember] !== currentMember) {
      currentMember = this.#parent[currentMember];
      this.#parent[currentMember] = this.#find(this.#parent[currentMember]);
    }
    return currentMember;
  }
}
