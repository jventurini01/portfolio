//is there a value for counter in localStorage?
if (!localStorage.getItem('counter')) {
    localStorage.setItem('counter', 0);
}

function count() {
    //get the counter value from localStorage and increment it by 1. 
    //change the h1's value to match the counter and store that value in LocalStorage for the next time they visit the page. 
    let counter = localStorage.getItem('counter');
    counter++;
    document.querySelector('h1').innerHTML = counter;
    localStorage.setItem('counter', counter );
}

document.addEventListener('DOMContentLoaded', function() {
    //When all content is loaded set the inner HTML of the H1 element to whatever the counter was.
    document.querySelector('h1').innerHTML = localStorage.getItem('counter');
    document.querySelector('button').onclick = count;
});