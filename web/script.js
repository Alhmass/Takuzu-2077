Module.onRuntimeInitialized = () => { start(); }

var canvas = document.getElementById('game-canvas');

/* ******************** assets ******************** */

// load mario image
var cursor = new Image();
cursor.src = "assets/img/cursor.png";

// initial position in canvas
var cursorX = 0;
var cursorY = 0;
var cursorW = 50;
var cursorH = 50;

var squareX = 0;
var squareY = 0;

/* ******************** register events ******************** */

window.addEventListener('load', windowLoad);              // window load
canvas.addEventListener('click', canvasLeftClick);        // left click event
canvas.addEventListener('contextmenu', canvasRightClick); // right click event

/* ******************** event callback ******************** */

function canvasLeftClick(event) {
    event.preventDefault(); // prevent default context menu to appear...
    // get relative cursor position in canvas
    console.log("left click at position:", event.offsetX, event.offsetY);
    // update position of cursor image used by drawCanvas()
    cursorX = event.offsetX - 8;
    cursorY = event.offsetY - 8;
    drawCanvas();
}

function canvasRightClick(event) {
    event.preventDefault(); // prevent default context menu to appear...
    // get relative cursor position in canvas
    console.log("right click at position:", event.offsetX, event.offsetY);
    // update position of mario image used by drawCanvas()
    squareX = event.offsetX;
    squareY = event.offsetY;
    drawCanvas();
}

function windowLoad() {
    console.log("window load");
    drawCanvas();
}

/* ******************** game grid ******************** */

function printGame(g) {
    var text = "";
    var nb_rows = Module._nb_rows(g);
    var nb_cols = Module._nb_cols(g);
    for (var row = 0; row < nb_rows; row++) {
        for (var col = 0; col < nb_cols; col++) {
            var square = Module._get_square(g, row, col);
            var immutable = Module._is_immutable(g, row, col);
            var empty = Module._is_empty(g, row, col);
            // var error = Module._has_error(g, row, col);
            if (empty)
                text += " ";
            else if (square == 3)
                text += "W";
            else if (square == 4)
                text += "B";
            else if (square == 1)
                text += "w";
            else if (square == 2)
                text += "b";
            else text += "?";
        }
        text += "\n";
    }

    // put this text in <div> element with ID 'result'
    var elm = document.getElementById('result');
    elm.innerHTML = text;
}

/* ******************** canvas drawing ******************** */

function drawCanvas() {
    var ctx = canvas.getContext('2d');
    var width = canvas.width;
    var height = canvas.height;
    var offsetX = canvas.offsetLeft;
    var offsetY = canvas.offsetTop;

    // clear canvas
    ctx.clearRect(0, 0, width, height);

    // draw a white square at (squareX, squareY) position
    ctx.save();
    ctx.fillStyle = 'white';
    ctx.fillRect(squareX - 20, squareY - 20, 40, 40);
    ctx.restore();

    // draw a centered text
    ctx.save();
    ctx.font = 'bold 20px Arial';
    ctx.fillStyle = 'cyan';
    ctx.textBaseline = 'middle';
    ctx.textAlign = 'center';
    ctx.fillText("Hello World!", width / 2, height / 2);
    ctx.restore();

    ctx.drawImage(cursor, cursorX, cursorY, cursorW, cursorH);
}

/* ******************** start ******************** */

function start() {
    console.log("call start routine");
    var g = Module._new_default();
    const LIGHTBULB = 1;
    Module._play_move(g, 0, 0, LIGHTBULB);
    printGame(g);
    Module._delete(g);
}

