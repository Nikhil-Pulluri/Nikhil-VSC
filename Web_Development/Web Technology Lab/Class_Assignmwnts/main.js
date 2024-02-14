// console.log("Hello")
function add() {
    var num1 = parseFloat(document.getElementById('one').value);
    var num2 = parseFloat(document.getElementById('two').value);
    var result = num1 + num2;
    document.getElementById('res').innerHTML = 'Result of addition: ' + result;
}

function subtract() {
    var num1 = parseFloat(document.getElementById('one').value);
    var num2 = parseFloat(document.getElementById('two').value);
    var result = num1 - num2;
    document.getElementById('res').innerText = 'Result of subtraction: ' + result;
}