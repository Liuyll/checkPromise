const binding = require('bindings')('checkPromise')

const checkPromiseStatusAsync = (p) => {
    const r = {}
    return Promise.race([p,r]).then(
        v => v === r ? 'pending' : 'fulfilled',
        () => 'rejected'
    )
}
module.exports = {
    checkPromise: binding.checkPromiseStatus,
    isPromise: binding.isPromise,
    checkPromiseAsync: checkPromiseStatusAsync
}