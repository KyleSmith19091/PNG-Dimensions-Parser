#include "../node_modules/node-addon-api/napi.h"
#include "pngParser.hpp"

Napi::Object getImageDimensions(const Napi::CallbackInfo& args) {
    Napi::Env env = args.Env();

    PngParser pngParser;
    auto dims = pngParser.getImageDimensions((std::string)args[0].ToString());

    auto dimensionsObj = Napi::Object::New(env);
    dimensionsObj.Set("width", dims.first);
    dimensionsObj.Set("height", dims.second);

    return dimensionsObj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(
            Napi::String::New(env, "getImageDimensions"),
            Napi::Function::New(env, getImageDimensions)
    );

    return exports;
}

NODE_API_MODULE(PngParser,Init);
