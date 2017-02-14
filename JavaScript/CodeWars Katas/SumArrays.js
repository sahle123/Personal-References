/* SumArrays.js
*
*	Sum of arrays in JavaScript
*
*	LU: 09/22/15
*/

// Solution to Sum array. Courtesy of MMMAAANNN
function arraySum(arr) {
  var output = 0;
  for (var i in arr) {
    var item = arr[i];
    if ( typeof(item) === "number"  )  { output += item;           }
    if ( item.constructor === Array )  { output += arraySum(item); }
  }
  return output;
}

// Test.assertEquals(arraySum([1, 2]), 3);
// Test.assertEquals(arraySum([1, 2, 3]), 6);
// Test.assertEquals(arraySum([1, 2, [1, 2]]), 6);