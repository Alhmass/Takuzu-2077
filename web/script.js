Module.onRuntimeInitialized = () => { start(); }

var canvas = document.getElementById('game-canvas');

/* ******************** assets ******************** */

var cursor = new Image();
cursor.src = "assets/img/cursor.png";

var cell_blue = new Image();
cell_blue.src = "assets/img/cell/blue.png";
var cell_imm_blue = new Image();
cell_imm_blue.src = "assets/img/cell/imm_blue.png";
var cell_red = new Image();
cell_red.src = "assets/img/cell/red.png";
var cell_imm_red = new Image();
cell_imm_red.src = "assets/img/cell/imm_red.png";
var cell_empty = new Image();
cell_empty.src = "assets/img/cell/empty.png";
var cell_hover = new Image();
cell_hover.src = "assets/img/cell/hover.png";
var cell_error = new Image();
cell_error.src = "assets/img/cell/error.png";


var rajdhani = new FontFace('Rajdhani', 'url(assets/fonts/Rajdhani-SemiBold.ttf)');
rajdhani.load().then(function (loaded_face) {
    document.fonts.add(loaded_face);
});

/* ******************** variables ******************** */

// initial position in canvas
var cursorX = 0;
var cursorY = 0;

// var squareX = 0;
// var squareY = 0;

/* ******************** register events ******************** */

window.addEventListener('load', windowLoad);              // window load
canvas.addEventListener('click', canvasLeftClick);        // left click event
canvas.addEventListener('contextmenu', canvasLeftClick); // right click event

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

function printGame(game) {
    var ctx = canvas.getContext('2d');
    var width = canvas.width;
    var height = canvas.height;
    ctx.clearRect(0, 0, width, height);

    var nb_rows = Module._nb_rows(game);
    var nb_cols = Module._nb_cols(game);
    var cell_width = width / nb_cols;
    var cell_height = height / nb_rows;

    for (var row = 0; row < nb_rows; row++) {
        for (var col = 0; col < nb_cols; col++) {
            var square = Module._get_square(game, row, col);
            var immutable = Module._is_immutable(game, row, col);
            var empty = Module._is_empty(game, row, col);
            var error = Module._has_error(game, row, col);
            if (empty)
                ctx.drawImage(cell_empty, col * cell_width, row * cell_height, width / nb_cols, height / nb_rows);
            else if (square == 3)
                ctx.drawImage(cell_imm_blue, col * cell_width, row * cell_height, width / nb_cols, height / nb_rows);
            else if (square == 4)
                ctx.drawImage(cell_imm_red, col * cell_width, row * cell_height, width / nb_cols, height / nb_rows);
            else if (square == 1)
                ctx.drawImage(cell_blue, col * cell_width, row * cell_height, width / nb_cols, height / nb_rows);
            else if (square == 2)
                ctx.drawImage(cell_red, col * cell_width, row * cell_height, width / nb_cols, height / nb_rows);
            if (error)
                ctx.drawImage(cell_error, col * cell_width, row * cell_height, width / nb_cols, height / nb_rows);
        }
    }

    // put this text in <div> element with ID 'result'
    var elm = document.getElementById('result');
}

/* ******************** canvas drawing ******************** */

function drawCanvas() {
    var ctx = canvas.getContext('2d');
    // var width = canvas.width;
    // var height = canvas.height;
    // ctx.clearRect(0, 0, width, height);

    ctx.drawImage(cursor, cursorX, cursorY, 50, 50);
}

/* ******************** start ******************** */

function start() {
    console.log("call start routine");
    const LIGHTBULB = 1;
    // Module._play_move(game, 0, 0, LIGHTBULB);
    var game = Module._new_default();
    printGame(game);
    Module._delete(game);
}

