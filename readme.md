# CheckPromise
Sync check promise status. But core of CheckPromise is written by c++.

## Motivation
`node.js` haven't expose one way to check a promise status. Although some trick can check promise status, that always are async way.

In addition, some monkey patch change promise constructor. you can't use `instanceof` to check a object whether is a promise.and more,like `zone.js`,although change promise constructor, the promise.then always return a promise maked by native Promise.This moment,you must use unconventional way to check. 

## Usages
### sync 
```
cp.checkPromise(Promise.resolve()) 
```

### async
```
cp.checkPromiseAsync(Promise.resolve).then(status => {
    if(...)
})
```

### isPromise
```
cp.isPromise(Promise.resolve)
```

## Installation
`yarn add checkPromise`

