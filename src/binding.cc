#include <node.h>
#include <nan.h>

extern "C" {
  #include "murmur3.h"
}

using namespace v8;
using namespace node;

NAN_METHOD(murmur3_x64_128) {
  NanScope();

  String::Utf8Value dataObject(args[0]->ToString());
  const char* data = *dataObject;
  uint32_t seed = args[1]->Uint32Value();
  Local<Function> cb = Local<Function>::Cast(args[2]);

  char* buffer = (char *)malloc(16);
  memset(buffer, 0, 16);
  MurmurHash3_x64_128(data, seed, dataObject.length(), buffer);

  Local<Value> result[2] = {
    NanNull(),
    NanNewBufferHandle(buffer, 16)
  };

  cb->Call(Context::GetCurrent()->Global(), 2, result);

  NanReturnUndefined();
}

NAN_METHOD(murmur3_x86_128) {
  NanScope();

  String::Utf8Value dataObject(args[0]->ToString());
  const char* data = *dataObject;
  uint32_t seed = args[1]->Uint32Value();
  Local<Function> cb = Local<Function>::Cast(args[2]);

  char* buffer = (char *)malloc(16);
  memset(buffer, 0, 16);
  MurmurHash3_x86_128(data, seed, dataObject.length(), buffer);

  Local<Value> result[2] = {
    NanNull(),
    NanNewBufferHandle(buffer, 16)
  };

  cb->Call(Context::GetCurrent()->Global(), 2, result);

  NanReturnUndefined();
}

NAN_METHOD(murmur3_x86_32) {
  NanScope();

  String::Utf8Value dataObject(args[0]->ToString());
  const char* data = *dataObject;
  uint32_t seed = args[1]->Uint32Value();
  Local<Function> cb = Local<Function>::Cast(args[2]);

  char* buffer = (char *)malloc(4);
  memset(buffer, 0, 4);
  MurmurHash3_x86_32(data, seed, dataObject.length(), buffer);

  Local<Value> result[2] = {
    NanNull(),
    NanNewBufferHandle(buffer, 4)
  };

  cb->Call(Context::GetCurrent()->Global(), 2, result);

  NanReturnUndefined();
}

void init(Handle<Object> target) {
   target->Set(NanNew<String>("murmur3_x64_128"),
           NanNew<FunctionTemplate>(murmur3_x64_128)->GetFunction());
   target->Set(NanNew<String>("murmur3_x86_128"),
           NanNew<FunctionTemplate>(murmur3_x86_128)->GetFunction());
   target->Set(NanNew<String>("murmur3_x86_32"),
           NanNew<FunctionTemplate>(murmur3_x86_32)->GetFunction());
}

NODE_MODULE(murmur3, init)

