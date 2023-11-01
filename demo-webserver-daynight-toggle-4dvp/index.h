#ifndef INDEX_H
#define INDEX_H

const char* HTML_CONTENT = R""""(
<!DOCTYPE html>

<html lang="fr">
<head>
  <meta charset="UTF-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1" >
  <title>Day-Night</title>
  <link rel="stylesheet" href="style.css">
  <script src="javascript.js"></script>
</head>

<body onload="maj_onload()">
<div class="content">
  <input type="checkbox" id="btn" onclick="toggleLed()">
  <label for="btn">
    <span class="track">
      <span class="txt"></span>
    </span>
    <span class="thumb">|||</span>
  </label>
</div>
  
</body> 
</html>
)"""";

#endif
