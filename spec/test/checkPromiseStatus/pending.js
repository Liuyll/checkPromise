const assert = require('assert'),
    cp = require('../../../index')

const fulfilledPromise = new Promise(() => {})
assert.strictEqual(cp.checkPromise(fulfilledPromise),'pending')