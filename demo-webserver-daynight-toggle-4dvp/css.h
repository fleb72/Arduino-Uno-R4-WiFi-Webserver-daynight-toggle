#ifndef CSS_H
#define CSS_H

/* constante CSS_CONTENT avec le code de la feuille de style CSS
 CSS MODERN LIGHTED TOGGLE d'après Josetxu (June 8, 2023)
 - vu sur https://freefrontend.com/css-toggle-switches/ (selection of free HTML and CSS toggle)
 - code & démo sur https://codepen.io/josetxu/pen/Poxwpme
*/

/* The MIT License (MIT)

Copyright (c) 2023 Josetxu  (https://codepen.io/josetxu/pen/Poxwpme)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

const char* CSS_CONTENT = R""""(  
@import url('https://fonts.googleapis.com/css2?family=Roboto:wght@500&display=swap');

:root {
  --sz: 10vmin;  /* size */
  --on: #2eddf3; /* color on */
  --of: #68838d; /* color off */
  --tr: all 0.25s ease 0s;
}	

* {
  box-sizing: border-box;
  transition: var(--tr);
}

body {
  margin: 0;
  padding: 0;
  width: 100vw;
  height: 100vh;
  overflow: hidden;
  display: flex;
  align-items: center;
  justify-content: center;
  background: linear-gradient(45deg, #486c7d, #dafbff);
  font-family: Roboto, Arial, Helvetica, serif;
}

.content {
  position: relative;
  width: calc(var(--sz) * 4);
  height: calc(var(--sz) * 2);
  display: flex;
  align-items: center;
  justify-content: center;
}

input {
  display: none;
}

label[for=btn] {
  position: absolute;
  width: calc(var(--sz) * 4);
  height: calc(var(--sz) * 2);
  background: linear-gradient(180deg, #888, #fff);
  border-radius: var(--sz);
  padding: calc(var(--sz) / 5);
  box-shadow: 0 0 calc(var(--sz) / 50) calc(var(--sz) / 50) #0002;
}	

#btn:checked + label[for=btn] {
  box-shadow: 
    0 calc(var(--sz) / 50) calc(var(--sz) / 5) #fff9, 
    0 0 calc(var(--sz) / 50) calc(var(--sz) / 50) #0002;
}

label[for=btn]:after {
  content: "";
  position: absolute;
  width: calc(100% - calc(calc(var(--sz) / 5) * 12));
  height: calc(100% - calc(calc(var(--sz) / 5) * 2));
  box-shadow: 0 0 calc(var(--sz) / 2) calc(var(--sz) / 10) var(--on), 0 0 calc(var(--sz) / 2) calc(var(--sz) / 10) #fff;
  border-radius: var(--sz);
  z-index: 0;
  opacity: 0;
  transition: var(--tr);
  animation: move-shadow 3s ease 0s 1;
}

#btn:checked + label[for=btn]:after {
  opacity: 1;
  width: calc(100% - calc(calc(var(--sz) / 5) * 4));
}

.track {
  position: absolute;
  width: calc(calc(var(--sz) * 4) - calc(var(--sz) / 2.5));
  height: calc(calc(var(--sz) * 2) - calc(var(--sz) / 2.5));
  border-radius: var(--sz);
  overflow: hidden;
}

.track:before {
  content: "";
  position: absolute;
  width: calc(200% - calc(calc(var(--sz) * 2) - calc(var(--sz) / 3)));
  height: 100%;
  left: -50%;
  transition: var(--tr);
  background: linear-gradient(90deg, var(--on) 50%, var(--of) 50%);
  animation: move-color 3s ease 0s 1;
}

.track:after {
  content: "";
  position: absolute;
  width: 100%;
  height: 100%;
  border-radius: var(--sz);
  box-shadow: 0 calc(var(--sz) / -10) calc(var(--sz) / 10) 0 #0005 inset, 0 calc(var(--sz) / 10) calc(var(--sz) / 10) 0 #0005 inset;
}

#btn:checked + label .track:before {
  left: 0%;
}

.thumb {
  position: absolute;
  width: calc(calc(var(--sz) * 2) - calc(var(--sz) / 3));
  height: calc(calc(var(--sz) * 2) - calc(var(--sz) / 3));
  top: calc(calc( var(--sz) / 10) + calc(var(--sz) / 15));
  left: calc(calc( var(--sz) / 10) + calc(var(--sz) / 15));
  background: linear-gradient(180deg, #fff, #afafaf);
  border-radius: var(--sz);
  box-shadow: 0 0 0 calc(var(--sz) / 50) #0002, 0 calc(var(--sz) / 10) calc(var(--sz) / 10) 0 #0008;
  cursor: pointer;
  font-size: calc(var(--sz) / 2);
  display: flex;
  align-items: center;
  justify-content: center;
  text-indent: calc(var(--sz) * -0.025);
  text-shadow: 
    calc(var(--sz) / -8000) calc(var(--sz) / -150) calc(var(--sz) / 50) #0008, 
    calc(var(--sz) / 150) calc(var(--sz) / 100) calc(var(--sz) / 50) #fff;
  color: #7d7c7c;
  z-index: 1;
  animation: move-thumb 3s ease 0s 1;
}

#btn:checked + label .thumb {
  left: calc(calc(100% - calc(calc(var(--sz) * 2) - calc(var(--sz) / 3))) - calc(calc( var(--sz) / 10) + calc(var(--sz) / 15)));
  color: var(--on);
  background: 
    radial-gradient(circle at 7% 50%, #fff calc(var(--sz) / 50), #fff0 calc(var(--sz) / 2)),
    radial-gradient(circle at 0 50%, var(--on) 10%, #fff0 60%), 
    linear-gradient(180deg, #fff, #afafaf);
  text-shadow: 
    0 0 calc(var(--sz) / 10) var(--on), 0 0 calc(var(--sz) / 5) #fff, 
    calc(var(--sz) / -8000) calc(var(--sz) / -150) calc(var(--sz) / 50) #0008, 
    calc(var(--sz) / 150) calc(var(--sz) / 100) calc(var(--sz) / 50) #fff;
}

.thumb:before {
  content: "";
  display: block;
  width: 70%;
  height: 70%;
  background: linear-gradient(180deg, #0008, #ccc, #fff);
  position: absolute;
  z-index: -1;
  border-radius: var(--sz);
  border: calc(var(--sz) / 50) solid #ddd;
}

.txt:before, 
.txt:after {
  content: "";
  position: absolute;
  left: calc(var(--sz) / 2);
  top: 25%;
  content: "ON";
  transition: var(--tr);
  font-size: calc(var(--sz) / 1.5);
  color: #000;
  opacity: 0.4;
  text-shadow: 0px -1px 1px #000, 0px 1px 2px #fff;
}

.txt:after {
  content: "OFF";
  left: calc(100% - calc(var(--sz) / 0.625));
}


/* initial animation */
@keyframes move-thumb {
  0%, 20%, 80%, 100% { 
    left: calc(calc( var(--sz) / 10) + calc(var(--sz) / 15));
    color: #7d7c7c;
    background: linear-gradient(180deg, #fff, #afafaf);
    text-shadow:  
      calc(var(--sz) / -8000) calc(var(--sz) / -150) calc(var(--sz) / 50) #0008, 
      calc(var(--sz) / 150) calc(var(--sz) / 100) calc(var(--sz) / 50) #fff;
  }
  30%, 70% {
    left: calc(calc(100% - calc(calc(var(--sz) * 2) - calc(var(--sz) / 3))) - calc(calc( var(--sz) / 10) + calc(var(--sz) / 15)));
    color: var(--on);
    background: 
      radial-gradient(circle at 7% 50%, #fff calc(var(--sz) / 50), #fff0 calc(var(--sz) / 2)),
      radial-gradient(circle at 0 50%, var(--on) 10%, #fff0 60%), 
      linear-gradient(180deg, #fff, #afafaf);
    text-shadow:
      0 0 calc(var(--sz) / 10) var(--on), 0 0 calc(var(--sz) / 5) #fff, 
      calc(var(--sz) / -8000) calc(var(--sz) / -150) calc(var(--sz) / 50) #0008, 
      calc(var(--sz) / 150) calc(var(--sz) / 100) calc(var(--sz) / 50) #fff;
  }
}

@keyframes move-color {
  0%, 20%, 80%, 100% { left: -50%; }
  30%, 70% { left: 0%; }
}


@keyframes move-shadow {
  0%, 20%, 80%, 100% { 
    opacity: 0;
    width: calc(100% - calc(calc(var(--sz) / 5) * 12));	
  }
  30%, 70% { 
    opacity: 1;
    width: calc(100% - calc(calc(var(--sz) / 5) * 4));
  }
}
)"""";

#endif
