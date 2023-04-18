Module.onRuntimeInitialized = () => { start(); }

var canvas = document.getElementById('game-canvas');

/* ******************** Start ******************** */

function start() {
    console.log("call start routine");
    GAME = Module._new_default();
}

/* ******************** Assets ******************** */

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

/* ******************** Variables ******************** */

var EMPTY = 0;
var BLUE = 1;
var RED = 2;
var IMM_BLUE = 3;
var IMM_RED = 4;

var CURSOR_TOGGLE = true;
var CURSOR_X = -100;
var CURSOR_Y = -100;

var CANVA_X = canvas.offsetLeft;
var CANVA_Y = canvas.offsetTop;
var CANVA_W = canvas.width;
var CANVA_H = canvas.height;

var CTX = canvas.getContext('2d');

var GAME = null;
var NB_ROWS = 0;
var NB_COLS = 0;
var CELL_DIM = 0;
var SELECT_X = 0;
var SELECT_Y = 0;

/* ******************** Register Events ******************** */

window.addEventListener('load', windowLoad);              // window load
window.addEventListener('windowresize', windowLoad);      // window resize event
window.addEventListener('keydown', keyDown);              // key down event
canvas.addEventListener('click', canvasLeftClick);        // left click event
canvas.addEventListener('contextmenu', canvasRightClick); // right click event
canvas.addEventListener('mousemove', canvasMouseMove);    // mouse move event
canvas.addEventListener('zoom', windowLoad);              // zoom event (ctrl + scroll)

/* ******************** Event Callback ******************** */

function canvasLeftClick(event) {
    event.preventDefault();
    CURSOR_X = event.offsetX - 8;
    CURSOR_Y = event.offsetY - 8;
    process();
    play_move(3);   // EMPTY -> BLUE -> RED
    printGame();
}

function canvasRightClick(event) {
    event.preventDefault();
    CURSOR_X = event.offsetX - 8;
    CURSOR_Y = event.offsetY - 8;
    process();
    play_move(4);   // EMPTY -> RED -> BLUE
    printGame();
}

function canvasMouseMove(event) {
    event.preventDefault();
    CURSOR_X = event.offsetX - 8;
    CURSOR_Y = event.offsetY - 8;
    process();
    mouse_move();
    printGame();
}

function windowLoad() {
    process();
    printGame();
}

/* ******************** Process ******************** */

function process() {
    // Game Update
    NB_ROWS = Module._nb_rows(GAME);
    NB_COLS = Module._nb_cols(GAME);
    if (NB_ROWS > NB_COLS) {
        CELL_DIM = CANVA_H / NB_ROWS;
    } else {
        CELL_DIM = CANVA_W / NB_COLS;
    }

    // Canva Update
    CTX = canvas.getContext('2d');
    CANVA_X = canvas.offsetLeft;
    CANVA_Y = canvas.offsetTop;
    canvas.width = (800 * 100 / 1920) * (window.innerWidth) / 100;
    canvas.height = canvas.width;
    CANVA_W = canvas.width;
    CANVA_H = canvas.height;

    CTX.clearRect(0, 0, CANVA_W, CANVA_H);
}

function printGame() {
    var cell_width = CANVA_W / NB_COLS;
    // var cell_height = CANVA_H / NB_ROWS;
    var cell_height = cell_width;

    for (var row = 0; row < NB_ROWS; row++) {
        for (var col = 0; col < NB_COLS; col++) {
            var square = Module._get_square(GAME, row, col);
            var error = Module._has_error(GAME, row, col);
            if (square == EMPTY)
                CTX.drawImage(cell_empty, col * cell_width, row * cell_height, cell_width, cell_height);
            else if (square == BLUE)
                CTX.drawImage(cell_blue, col * cell_width, row * cell_height, cell_width, cell_height);
            else if (square == RED)
                CTX.drawImage(cell_red, col * cell_width, row * cell_height, cell_width, cell_height);
            else if (square == IMM_BLUE)
                CTX.drawImage(cell_imm_blue, col * cell_width, row * cell_height, cell_width, cell_height);
            else if (square == IMM_RED)
                CTX.drawImage(cell_imm_red, col * cell_width, row * cell_height, cell_width, cell_height);

            if (error && (square == BLUE || square == RED) && ERROR_TOGGLE)
                CTX.drawImage(cell_error, col * cell_width, row * cell_height, cell_width, cell_height);
        }
    }

    if (HOVER_TOGGLE)
        CTX.drawImage(cell_hover, SELECT_X * CANVA_W / NB_COLS, SELECT_Y * CANVA_H / NB_ROWS, CANVA_W / NB_COLS, CANVA_H / NB_ROWS);

    if (Module._is_over(GAME)) {
        canvas.style.boxShadow = "0 0 30px 20px rgba(111, 255, 147, 0.5)";
        canvas.style.outline = "5px solid rgba(111, 255, 147, 1)";
    } else {
        canvas.style.boxShadow = "0 0 30px 20px rgba(144, 245, 249, 0.3)";
        canvas.style.outline = "5px solid rgba(144, 245, 249, 1)";
    }

    if (CURSOR_TOGGLE)
        CTX.drawImage(cursor, CURSOR_X, CURSOR_Y, 50, 50);

    // put this text in <div> element with ID 'result'
    var elm = document.getElementById('result');
}

function play_move(mode) {
    var square = Module._get_square(GAME, SELECT_Y, SELECT_X);
    if (mode == 3) {
        square++;
        if (square > RED)
            square = EMPTY;
    } else if (mode == 4) {
        square--;
        if (square < EMPTY)
            square = RED;
    } else {
        square = mode;
    }

    if (!Module._is_immutable(GAME, SELECT_Y, SELECT_X))
        Module._play_move(GAME, SELECT_Y, SELECT_X, square);
}

/* ******************** Input ******************** */

function mouse_move() {
    CURSOR_TOGGLE = true;
    SELECT_X = Math.floor(CURSOR_X * NB_COLS / CANVA_W);
    SELECT_Y = Math.floor(CURSOR_Y * NB_ROWS / CANVA_H);
}

function keyDown(event) {
    switch (event.key) {
        case "ArrowUp":
        case "z":
            SELECT_Y -= 1;
            if (SELECT_Y < 0)
                SELECT_Y = NB_ROWS - 1;
            CURSOR_TOGGLE = false;
            break;
        case "ArrowDown":
        case "s":
            SELECT_Y += 1;
            if (SELECT_Y >= NB_ROWS)
                SELECT_Y = 0;
            CURSOR_TOGGLE = false;
            break;
        case "ArrowLeft":
        case "q":
            SELECT_X -= 1;
            if (SELECT_X < 0)
                SELECT_X = NB_COLS - 1;
            CURSOR_TOGGLE = false;
            break;
        case "ArrowRight":
        case "d":
            SELECT_X += 1;
            if (SELECT_X >= NB_COLS)
                SELECT_X = 0;
            CURSOR_TOGGLE = false;
            break;
        case "0":
            play_move(EMPTY);
            break;
        case "1":
            play_move(BLUE);
            break;
        case "2":
            play_move(RED);
            break;
        case "4":
            play_move(3);
            break;
        case "5":
            play_move(4);
            break;
        case "r":
            restart();
            break;
        case "a":
            undo();
            break;
        case "e":
            redo();
            break;
        case "m":
            solve();
            break;
        case "k":
            document.getElementById('hover_switch').click();
            break;
        case "l":
            document.getElementById('error_switch').click();
            break;
        default:
            return; // Quit when this doesn't handle the key event.
    }

    CTX.clearRect(0, 0, CANVA_W, CANVA_H);
    printGame();

    // Cancel the default action to avoid it being handled twice
    event.preventDefault();
}

/* ******************** Button Functions ******************** */

function restart() { process(); Module._restart(GAME); printGame(); }
function undo() { process(); Module._undo(GAME); printGame(); }
function redo() { process(); Module._redo(GAME); printGame(); }
function solve() { process(); Module._solve(GAME); printGame(); }
function blue() { process(); play_move(BLUE); printGame(); }
function red() { process(); play_move(RED); printGame(); }
function empty() { process(); play_move(EMPTY); printGame(); }
function random() {
    GAME = Module._delete(GAME);
    GAME = Module._new_random(6, 6, false, false);
    process();
    printGame();
}

/* ******************** Switch Functions ******************** */

function classToggle() {
    this.classList.toggle('on');
    this.classList.toggle('off');
}
const buttons = document.querySelectorAll('.switch');
// Add a click event listener to each button
buttons.forEach((button) => {
    button.addEventListener('click', classToggle);
});

var MUSIC_TOGGLE = false;
function music_switch() {
    if (MUSIC_TOGGLE) {
        menu_audio.pause();
    } else {
        menu_audio.play();
    }
    MUSIC_TOGGLE = !MUSIC_TOGGLE;
}

var SOUND_TOGGLE = false;
function sounds_switch() {
    if (SOUND_TOGGLE) {
        negative_sound.play();
    } else {
        positive_sound.play();
    }
    SOUND_TOGGLE = !SOUND_TOGGLE;
}

var HOVER_TOGGLE = true;
function hover_switch() {
    if (HOVER_TOGGLE) {
        negative_sound.play();
    } else {
        positive_sound.play();
    }
    HOVER_TOGGLE = !HOVER_TOGGLE;
    CTX.clearRect(0, 0, CANVA_W, CANVA_H);
    printGame();
}

var ERROR_TOGGLE = true;
function error_switch() {
    if (ERROR_TOGGLE) {
        negative_sound.play();
    } else {
        positive_sound.play();
    }
    ERROR_TOGGLE = !ERROR_TOGGLE;
    CTX.clearRect(0, 0, CANVA_W, CANVA_H);
    printGame();
}

/* ******************** Audio ******************** */

// Hover Effect
var hover_sound = new Audio('assets/sounds/hover.wav');
hover_sound.volume = 0.1;
var positive_sound = new Audio('assets/sounds/positive.wav');
positive_sound.volume = 0.1;
var negative_sound = new Audio('assets/sounds/negative.wav');
negative_sound.volume = 0.1;

function hover_effect() { if (SOUND_TOGGLE) hover_sound.play(); }

// Menu Audio
const menu_audio = document.getElementById('menu_audio');
menu_audio.volume = 0.1;
