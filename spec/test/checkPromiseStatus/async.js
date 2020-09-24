const assert = require('assert'),
    cp = require('../../../index')

const fulfilledPromise = Promise.resolve()
cp.checkPromiseAsync(fulfilledPromise).then(s => assert.strictEqual(s,'fulfilled'))