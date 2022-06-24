<template>
<div id="app">
    <UI 
    @AddPoint="AddPoint"
    @DeleteCurve="DeleteCurve"
    ></UI>
    <Chart :controlDots="controlDots"></Chart>

</div>
</template>

<script>
import Chart from "./components/Chart";
import UI from './components/UI.vue';


export default {
  name: 'App',
  data: () => ({
    controlDots: {
    type: String,
    default: () => ""
    }

  }),
  components: {
    UI,
    Chart
},

  methods:{
    AddPoint(dots){
      this.controlDots = dots
    },
    DeleteCurve(){
      this.controlDots = ""
    }
  }
}
</script>



<style src="./assets/css/app.css">  </style>
