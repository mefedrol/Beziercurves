var bezier = require('./Bezier.js');

var Bezierlib;
bezier().then( module => {
Bezierlib = module;
    
    //Bezierlib.gce_api.prototype.EnableMathModules(name, name.length, key, key.length);
    
    var bezier_api = new Bezierlib.bezier_functions()  // api functions
   // var bezier = c3d_solver_api.GCE_CreateSystem();  // to create C3D Solver system
    
    var curve = bezier_api.CreateBezierCurve("-100 -50 -100 50 100 -50 100 50"); 
    
    console.log(curve);

    var polyline = bezier_api.PolyLine(curve);

    console.log(polyline);

});