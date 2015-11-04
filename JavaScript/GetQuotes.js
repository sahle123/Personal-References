/*GetQuotes.js
*
*	Extract only quoted phrases from a string. This is an EXCELLENT example
*	on illustrating how greediness/laziness works in regex.
*
*	Nov 3rd, 2015
*/

var reg = /".+?"/g; // reg = /"([^"])"/g works just as well.

function getQuotes(string)
{
	console.log(string.match(reg)); // For viewing outputs

	return string.match(reg);
}

/* Test case

Test.assertSimilar(getQuotes('"Winners never quit and quitters never win." - Vince Lombardi, "My motto is, \'Never quit.\'" - Henry Rollins')
,["\"Winners never quit and quitters never win.\"","\"My motto is, 'Never quit.'\""]);

*/