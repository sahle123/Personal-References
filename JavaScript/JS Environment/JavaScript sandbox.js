/*
* Test environment for JS code
*/

// Anonymous function assigned to helloFunction()

function main() {
  console.log("I'm empty at the moment.");
}


// For testing if HTML is working.
helloFunction = function() {
  console.log("Hello world, I am helloFunction!");
}

// Just more test code...
function formatDateTime(format) {
  var result;
  var date = new Date();
  var year = date.getFullYear().toString();
  var month = (date.getMonth() + 1).toString();
  var day = date.getDate().toString()

  if(format === 0)
    result = month + "/" + day + "/" + year;
  else
    result = day + "/" + month + "/" + year;

  console.log("Date is: " + result);
}
