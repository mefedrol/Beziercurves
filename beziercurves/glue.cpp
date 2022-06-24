
#include <emscripten.h>

extern "C" {

// Not using size_t for array indices as the values used by the javascript code are signed.

EM_JS(void, array_bounds_check_error, (size_t idx, size_t size), {
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

char* EMSCRIPTEN_KEEPALIVE emscripten_bind_bezier_functions_PolyLine_1(bezier_functions* self, void* crv) {
  return self->PolyLine(crv);
}

void* EMSCRIPTEN_KEEPALIVE emscripten_bind_bezier_functions_SetCurvature_3(bezier_functions* self, void* crv, double t, double curvature) {
  return self->SetCurvature(crv, t, curvature);
}

double EMSCRIPTEN_KEEPALIVE emscripten_bind_bezier_functions_GetCurvature_2(bezier_functions* self, void* crv, double t) {
  return self->GetCurvature(crv, t);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_bezier_functions___destroy___0(bezier_functions* self) {
  delete self;
}

}

