#ifndef JAVASCRIPT_H
#define JAVASCRIPT_H

/* constante JAVASCRIPT avec le code JavaScript */
const char* JAVASCRIPT_CONTENT = R""""(  
  function refresh(state) {
    if (state == "ON") {
      document.getElementById("btn").checked = true;
      document.body.style.background = "linear-gradient(45deg, #486c7d, #dafbff)";
    } else {
      document.getElementById("btn").checked = false;
      document.body.style.background = "linear-gradient(45deg, #000000, #dafbff)";
    }
  }

  function toggleLed() {
    btn = document.getElementById("btn");
    var url = "/toggle_led?switch=";
    url += btn.checked ? "1" : "0";
    //console.log(url);
   
    fetch(url)
    .then(res => res.json())
    .then(data => {
        console.log(data);
        refresh(data.led_state);
      });      
    }

  function maj_onload() {
    fetch("/maj_onload")
    .then(res => res.json())
    .then(data => {
        console.log(data);
        refresh(data.led_state);
      });  
    }
)"""";

#endif
