let turn="X";
let gameover=false;
let h3=document.getElementById('line');
let p=document.getElementsByClassName('info');
function changeturn()
{
  return turn==="X"?"0":"X";
}
function ganeover()
{

}
function checkwin(){
    let boxtext=document.getElementsByClassName('boxtext');
    let wins = [
      [0 , 1 , 2],
      [3 , 4 , 5],
      [6 , 7 , 8],
      [0 , 3 , 6],
      [1 , 4 , 7],
      [2 , 5 , 8],
      [0 , 4 , 8],
      [2 , 4 , 6],  
    ]
    wins.forEach(e =>
      {
        if((boxtext[e[0]].innerText === boxtext[e[1]].innerText) && (boxtext[e[1]].innerText === boxtext[e[2]].innerText) && (boxtext[e[2]].innerText === boxtext[e[0]].innerText) && boxtext[e[0]].innerText!='')
        {
           document.querySelector('#line').innerText = boxtext[e[0]].innerText + " won "
           gameover=true;
           p.innerText = "Yahoo...Game Finished";
        }
      })
}
let boxes=document.getElementsByClassName("box");
Array.from(boxes).forEach(element =>{
  let boxtext=element.querySelector(".boxtext");
  element.addEventListener('click',()=>
  {
    if(boxtext.innerText==='')
    {
      boxtext.innerText=turn;
      turn=changeturn();console.log(gameover)
      checkwin();
      console.log(gameover);
      if(!gameover)
      {
       
        h3.innerText = " turn for " + turn;
      }

    }
  })
})
reset.addEventListener('click',()=>
{
let boxtexts=document.querySelectorAll(".boxtext");
console.log("reseting")
Array.from(boxtexts).forEach(element=>{
  element.innerText='';
});
turn= "X";
gameover=false;
// h3.innerText = " turn for " s+ turn;
})