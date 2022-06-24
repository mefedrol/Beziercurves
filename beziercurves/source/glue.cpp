
#include <emscripten.h>

extern "C" {

// Not using size_t for array indices as the values used by the javascript code are signed.

EM_JS(void, array_bounds_check_error, (int idx, int size), {
  throw 'Array index ' + idx + ' out of bounds: [0,' + size + ')';
});

void array_bounds_check(const int array_size, const int array_idx) {
  if (array_idx < 0 || array_idx >= array_size) {
    array_bounds_check_error(array_idx, array_size);
  }
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

// bezier_functions

bezier_functions* EMSCRIPTEN_KEEPALIVE emscripten_bind_bezier_functions_bezier_functions_0() {
  return new bezier_functions();
}

void* EMSCRIPTEN_KEEPALIVE emscripten_bind_bezier_functions_CreateBezierCurve_1(bezier_functions* self, char* dots) {
  return self->CreateBezierCurve(dots);
}

const char* EMSCRIPTEN_KEEPALIVE emscripten_bind_bezier_functions_PolyLine_1(bezier_functions* self, void* pntr) {
  return self->PolyLine(pntr);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_bezier_functions___destroy___0(bezier_functions* self) {
  delete self;
}

}

