#include <node_api.h>
#include <assert.h>
#include <v8.h>
#include <string>

using namespace v8;
using namespace std;

napi_value isPromise(
    napi_env env,
    napi_callback_info info
) {
    napi_status status;
    size_t argc = 1;
    napi_value argv[1];

    status = napi_get_cb_info(env,info,&argc,argv,NULL,NULL);
    assert(status == napi_ok);

    napi_valuetype targetType;
    status = napi_typeof(env,argv[0],&targetType);
    assert(status == napi_ok);

    if(targetType != napi_object) return 0;

    bool _isPromise;
    status = napi_is_promise(env,argv[0],&_isPromise);
    assert(status == napi_ok);

    napi_value ret;
    status = napi_get_boolean(env, _isPromise, &ret);
    assert(status == napi_ok);

    return ret;
}

napi_value checkPromiseStatus(
    napi_env env,
    napi_callback_info info
) {
    napi_status status;
    size_t argc = 1;
    napi_value argv[1];

    status = napi_get_cb_info(env,info,&argc,argv,NULL,NULL);
    assert(status == napi_ok);

    napi_valuetype targetType;
    status = napi_typeof(env,argv[0],&targetType);
    assert(status == napi_ok);

    if(targetType != napi_object) return 0;

    Promise *promise = (Promise*)((void*)argv[0]);
    Promise::PromiseState state;

    string ret;
    napi_value return_ret;
    switch (promise -> State())
    {
    case Promise::kPending:
        ret = "pending";
        break;
    case Promise::kFulfilled:
        ret = "fulfilled";
        break;
    case Promise::kRejected:
        ret = "rejected";
    }

    status = napi_create_string_utf8(env,(char *)ret.c_str(),ret.size(),&return_ret);
    assert(status == napi_ok);
    return return_ret;
}

napi_value init(napi_env env,napi_value exports) {
    napi_status status;
    napi_value isPromise_fn;
    napi_value checkPromiseStatus_fn;

    status = napi_create_function(env,"checkPromiseStatus",NAPI_AUTO_LENGTH,checkPromiseStatus,nullptr,&checkPromiseStatus_fn);
    if(status != napi_ok) return nullptr;

    status = napi_create_function(env,"isPromise",NAPI_AUTO_LENGTH,isPromise,nullptr,&isPromise_fn);
    if(status != napi_ok) return nullptr;

    status = napi_set_named_property(env,exports,"isPromise",isPromise_fn);
    status = napi_set_named_property(env,exports,"checkPromiseStatus",checkPromiseStatus_fn);

    if(status != napi_ok) return nullptr;
    return exports;
}


NAPI_MODULE(NODE_GYP_MODULE_NAME, init);
