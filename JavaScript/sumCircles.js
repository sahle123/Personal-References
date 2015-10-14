/* sumCircles.js
*
*	Check sum_circles.py for a description
*/
function sumCircles() 
{

	var result = 0;
  
	for(var i = 0; i < arguments.length; ++i)
	{
		// Area of circle
		var leArea = Math.PI*Math.pow((arguments[i]/2), 2);
		result = result + leArea;
	}
  // Round of the area
  result = Math.round(result);
  
	return ("We have this much circle: " + result);

}