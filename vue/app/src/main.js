

import { createApp } from 'vue'
import App from './App.vue'

createApp(App).mount('#app')


/*
import Vue from 'vue'
import App from './App.vue'
import VueWasm from 'vue-wasm';
import Bezier from './assets/wasm/Bezier.wasm';

const init = async () => {
  await VueWasm(Vue, { modules: { arithmetic: Bezier } });
  
  new Vue({
    el: '#app',
    template: '<App/>',
    components: { App },
  });
};

init();
*/
