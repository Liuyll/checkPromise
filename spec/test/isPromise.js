const assert = require('assert'),
    cp = require('../../index')

const promise = new Promise(() => {}),
    nonPromise = {}
assert.strictEqual(cp.isPromise(promise),true)

assert.strictEqual(cp.isPromise(nonPromise),false)
