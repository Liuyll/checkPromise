const assert = require('assert'),
    process = require('process'),
    cp = require('../../../index')

const noop = () => {}
process.on('unhandledRejection',noop)

const fulfilledPromise = Promise.reject()
assert.strictEqual(cp.checkPromise(fulfilledPromise),'rejected')