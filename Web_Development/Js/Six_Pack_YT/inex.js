// let heading = document.getElementById("head");

// let s = "Hi ra puka!";


// let str = `My name is Nikhil`;

// let arr = [1,2,3];

// // heading.innerText= ` ${str} okay! I got it now`;
// heading.innerText= "okay! I got it now " + arr;

// let a = 20;

// {
//     a = 30;
//     console.log(a);
// }

// console.log(a);

var semester = new Object;

semester.subjects = 2;
semester.faculty = 3;

// const a = document.getElementById("head");

// a.innerHTML(`The elements in the object are:`);
// semester.forEach(key,value => {
//     console.log(value,key);
// });

for(var i in semester){
    console.log(semester[i]);
}