const assert = require('assert'),
    cp = require('../../../index')

const fulfilledPromise = Promise.resolve()
assert.strictEqual(cp.checkPromise(fulfilledPromise),'fulfilled')