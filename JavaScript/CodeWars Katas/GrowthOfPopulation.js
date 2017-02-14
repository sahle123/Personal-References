/*
*   Growth of population Kata. CodeWars
*   LU: 02/14/17
*/

function nbYear(p0, percent, aug, p) {
	var y = 0;

	while(p0 < p)
  {
  	p0 = (p0 + p0*(percent/100) + aug);
  	y += 1;	
  }

  return y;
}

?
/* Test code

Test.describe("nbYear",function() {
Test.it("Basic tests",function() {
    Test.assertEquals(nbYear(1500, 5, 100, 5000), 15);
    Test.assertEquals(nbYear(1500000, 2.5, 10000, 2000000), 10);
    Test.assertEquals(nbYear(1500000, 0.25, 1000, 2000000), 94);
})})

*/
