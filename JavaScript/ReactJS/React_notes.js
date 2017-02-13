/*
*   React.js notes and reference code from Codecademy.
*   LU: 01/01/17
*/
//------------------------------------------------------------------------------
// General Notes
// React.js uses JSX, which is a syntax extension for JavaScript. In this case
// browsers do not recognize JSX and it must be compiled into native JS in order
// for it to work. JSX compiler required.

// JSX elements are treated as JS expressions.
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Basics

// JSX element with nested HTML. Must be wrapped in parenthesis to be valid.
var myDiv = (
  <div>
    <h1>Hello world</h1>
  </div>
);

// JSX expressions must have only one outer most element in it. Below is an
// example that is correct and incorrect, respectively.
var IamValid = (
  <div>
    <p>Hello!</p>
    <p>Salute!</p>
  </div>
);

//var IamNotValid = (
//  <p>Hello!</p>
//  <p>Salute!</p>
//);

// To render JSX onto a view, the following method must be called.
// Note that if this is called twice, the second call will do nothing.
// This is part of what makes React fast, it uses a virtual DOM to accomplish
// this.
ReactDOM.render(IamValid, document.getElementById('myAppID'));

//------------------------------------------------------------------------------
// Advanced

// PITFALL: The 'class' attribute in HTML tags cannot be used in JSX code since
// class is a reserved keyword in JS. Instead, one uses 'className'.
var watchOut = (
  <div className="Big_boi">
    <label>Buk lao wuz here.</label>
  </div>
);

// PITFALL: Self-closing HTML tags in JSX must have the suffix '/' otherwise
// there will be a compilation error.

// HTML surrounded with curly braces will be treated as JS code. This is a
// powerful feature in React--use it well. Scope for the injected JS is the
// contained file.
var jhtml = (
  <h1>3 + 2 = {2 + 3}</h1>, document.getElementById('myAppID')
);
// Output: 3+ 2 = 5

// It is common practice to put attribute parameters into a JS object and assign
// them accordingly.
var pic_attributes = {
  duck: "someURL.com",
  chocobo: "finalfantasy.com"
};

var chocobo_pic = (
  <img
    src={pic_attributes.chocobo}
    alt="Kweh!" />
);

// JSX can work with HTML event listeners.

// Conditionals:
// 'If' statements CANNOT be injected into JSX elements. Instead, conditionals
// should be put outside of the called JSX element. Below is an example to
// help illustrate.
function coinToss(){
  return Math.random() < 0.5 ? 'heads' ? 'tails';
}

if (coinToss === 'heads'){
  var ans = "It's heads!";
} else {
  var ans = "It's tails!";
}

ReactDOM.render(ans, getElementById('myAppId'));

//
// Using .map method to create lists efficiently.
var React = require('react');
var ReactDOM = require('react-dom');

var people = ['Rowe', 'Prevost', 'Gare'];
var peopleLIs = people.map(function(person, i){
  // The key attribute is specific to React. Used for ordering lists
  // properly.
	return <li key="person_" + i>{person}</li>;
});

ReactDOM.render(<ul>{peopleLIs}</ul>, document.getElementById('app'));

//
// Writing non-JSX expressions.
var jsx_expression = <h1>Hello world</h1>;
var non_jsx = React.createElement(
  "h1",
  null,
  "Hello world"
);
// Both of the above expressions are equivalent, but the second variable is
// non-JSX.


//
// ...

//------------------------------------------------------------------------------
