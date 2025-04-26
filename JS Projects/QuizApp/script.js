const questions=[
    {
        question:"which is largest animal in the world?",
        answers:[
            { text:"Shark",correct:false},
            { text:"Blue Whale",correct:true},
            { text:"Giraffe",correct:false},
            { text:"Elephant",correct:false},
        ]
    },
    {
        question:"who am I?",
        answers:[
            { text:"Dog",correct:false},
            { text:"Bird",correct:false},
            { text:"HumanBeing",correct:true},
            { text:"Insect",correct:false},
        ]
    },
    {
        question:"what am studying?",
        answers:[
            { text:"BTech",correct:true},
            { text:"10th",correct:false},
            { text:"Intermediate",correct:false},
            { text:"Degree",correct:false},
        ]
    },
    {
        question:"where I live?",
        answers:[
            { text:"HYD",correct:false},
            { text:"America",correct:false},
            { text:"Antarctica",correct:false},
            { text:"Aloor",correct:true},
        ]
    },
];
const question=document.getElementById("question")
const answerbtn=document.getElementById("answer");
const nextbtn=document.getElementById("nextbutton");
let currentquestionindex=0;
let score=0;
function startquiz()
{
    currentquestionindex=0;
    score=0;
    nextbtn.innerHTML= "Next";
    showQuestion();
}
function showQuestion()
{
    resetstate();
    let currentquestion=questions[currentquestionindex];
    let questionNo=currentquestionindex + 1;
    question.innerHTML=questionNo + " . " + currentquestion.question;
    currentquestion.answers.forEach(answer => {
    const button=document.createElement("button");
    button.innerHTML=answer.text;
    button.classList.add("btn");
    answerbtn.appendChild(button);
    if(answer.correct)
    {
        button.dataset.correct = answer.correct;
    }
    button.addEventListener("click",selectAnswer);
    });                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
}
function  resetstate()
{
    console.log("reset");
    nextbtn.style.display = "none";
    while(answerbtn.firstChild)
    {
        answerbtn.removeChild(answerbtn.firstChild);
}
}
function selectAnswer(e)
{
    const selectedbtn = e.target;
    const iscorrect = selectedbtn.dataset.correct === "true";
    if(iscorrect)
    {
        selectedbtn.classList.add("correct");
        score++;
    }
    else{
        selectedbtn.classList.add("incorrect");
    }
    Array.from(answerbtn.children).forEach(button => {
        if(button.dataset.correct === "true")
        {
            button.classList.add("correct");
        }
        button.disabled = "true";
        });
        nextbtn.style.display = "block";
}
function showscore()
{
    resetstate();
    question.innerHTML = "YOU SCORED " + score;
    nextbtn.innerHTML = "Play Again";
    nextbtn.style.display = "block";
}
function  handleNextButton()
{
    currentquestionindex++;
    if(currentquestionindex < questions.length)
    {
        showQuestion();
    }
    else
    {
        showscore();
    }
}
nextbtn.addEventListener("click",() => {
    if(currentquestionindex < questions.length)
    {
        handleNextButton();
    }
    else
    {
        startquiz();
    }
})
startquiz();

