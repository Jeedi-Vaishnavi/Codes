h1=document.querySelector("h1");
function changecolor(temp,delay){
    return new Promise((resolve,reject) => {
    setTimeout(() => {
        h1.style.color=temp;
        resolve("color changed");
    },delay);
}); 
}
changecolor("red",1000)
.then(() =>{
    console.log("red completed");
    return changecolor("orange",1000);
})
.then(() =>{
    console.log("orange completed");
    return changecolor("blue",1000);
})
.then(() =>{
    console.log("blue completed");
    return changecolor("green",1000);
});

