
<template>
  <div>
    <div class="page">
      <div class="buttons">
        <button @click="AddPoint">{{msg}}</button>
        <tr></tr>
        <input          
          v-if="show"
          :controlDots="controlDots"
          type="text"
          @input="InputDots($event.target.value)"

        >
        <button @click="ChangeCount">Изменить кривизну</button>
        <tr></tr>
        <textarea          
          type="text"
          
        ></textarea>
        <tr></tr>
        <button @click="DeleteCurve">Удалить кривую</button>
      </div>
    </div>
  </div>
</template>

<script>

export default {
  emits: ['AddPoint', 'DeleteCurve'],
  name: 'UI',

  data() { 
    return {
      show: false,
      msg: "Добавить кривую",
      controlDots: {
      type: String,
      default: () => ""
    }
    }
  },

  methods: {
    AddPoint() {
      this.show = !this.show;
      if (this.show){
        this.msg = "Завершить добавление"
      }else{
        this.$emit('AddPoint', this.controlDots)
        this.msg = "Добавить кривую"
      }
    },

    DeleteCurve(){
        this.$emit('DeleteCurve', this.controlDots)
    },
    
    InputDots(value) {
      this.controlDots = value
    }
  }
  
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style src="../assets/css/UI.css">

</style>
