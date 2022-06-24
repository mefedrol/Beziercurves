<template>
<div class="chart">
  <div ref="canvasContainer"></div>
</div>
</template>

<script>
import * as THREE from "three";
import { MeshLine, MeshLineMaterial } from 'three.meshline';
//import * as Bezier_functions from './Bezier_functions';


export default {
  name: "TheCanvas",

  props: {
    controlDots: {
    type: String,
    default: () => ""
    }
  },
  mounted() {
    // scene, camera, renderer

    var scene = new THREE.Scene();
    var width = window.innerWidth - 350; 
    var height = window.innerHeight - 100;
    var camera = new THREE.OrthographicCamera( width / - 10, width / 10, height / 10, height / - 10, 1, 1000);

    camera.position.z = 200;

  
    var renderer = new THREE.WebGLRenderer();
    renderer.setSize(width, height);
    renderer.setClearColor(0x000000, 0.01)
    // Append to DOM

    this.$refs.canvasContainer.appendChild(renderer.domElement);

    const renderingParent = new THREE.Object3D();
    renderingParent.name = "Rendering parent";
    scene.add(renderingParent);

    var x;
    var y;
    var k = 0;
    var temp = [];
    
    const ChangeLine = () => {

    temp = this.controlDots.split(" ")
    var points = [];

    for (let value of temp) {
      if (k === 0){
      x = value;
      k++;
      } else {
      y = value;
      k--;
      points.push(x, y, 0);
      }
    }
    //pntr = Bezier_functions.Curve(this.controlDots)
    //points = Bezier_functions.Polyline(pntr)
    line.setPoints(points)
    };

    const line = new MeshLine();

    const material = new MeshLineMaterial({color: 0x280069, lineWidth: 1.5});
    const mesh = new THREE.Mesh(line, material);

    renderingParent.add(mesh);



    // Animation

    var animate = function() {
      requestAnimationFrame(animate);

      ChangeLine();

      renderer.render(scene, camera);
    };

    animate();
  }
};
</script>

<style src="../assets/css/chart.css"></style>