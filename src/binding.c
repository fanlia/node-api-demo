
#include <node_api.h>

static napi_value foo(napi_env env, napi_callback_info info) {

    napi_value result;
    if (napi_create_int32(env, 42, &result) != napi_ok) {
        napi_throw_error(env, NULL, "Failed to create return value");
        return NULL;
    }

    return result;
}

napi_value napi_register_module_v1(napi_env env, napi_value exports) {
    napi_value function;
    if (napi_create_function(env, NULL, 0, foo, NULL, &function) != napi_ok) {
        napi_throw_error(env, NULL, "Failed to create function");
        return NULL;
    }

    if (napi_set_named_property(env, exports, "foo", function) != napi_ok) {
        napi_throw_error(env, NULL, "Failed to add function to exports");
        return NULL;
    }

    return exports;
}

