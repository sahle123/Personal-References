/*CompareDates.js
*
*   Using dates in JavaScript and comparing them.
*   LU: 10/04/15
*/

function checkCoupon(enteredCode, correctCode, currentDate, expirationDate){
  
  if(correctCode === enteredCode)
  {
    // Convert currentDate and expirationDate to appropriate format
    var intCurrentDate = parseInt(Date.parse(currentDate));
    var intExpireDate = parseInt(Date.parse(expirationDate));
    console.log(intCurrentDate);
    console.log(intExpireDate);
    
    // Compare dates
    if(intCurrentDate <= intExpireDate)
      return true;
    
    return false;
  }
  else
    return false;
    
  // Code should never reach here.
  return false;
}