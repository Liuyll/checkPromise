const assert = require('assert'),
    cp = require('../../../index')

const fulfilledPromise = Promise.resolve().then(v => {})
assert.strictEqual(cp.checkPromise(fulfilledPromise),'pending')