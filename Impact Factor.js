function main() {
    // write your code here.
    // call functions `nextString`, `nextFloat` and `nextInt` 
    // to read the next token of input (ignoring whitespace)
    // Alternatively, you can create your own input parser functions
    // use console.log() to write to stdout

    var n = nextInt();
    var publics = JSON.parse(nextString());
    var journals = publics["publications"].map(p => {
        return {
            "title": p["publicationTitle"],
            "number": parseInt(p["publicationNumber"]),
            "count": p["articleCounts"].filter(p => (p["year"] == '2017' || p["year"] == '2018'))
            .map(a => parseInt(a["articleCount"])).reduce((x, y) => x + y)
        };
    });
    var numbers = new Map();
    journals.forEach(j => numbers.set(j["number"], 0));
    var citations = []
    
    for(var i = 1; i < n; i++) {
        var tmp = JSON.parse(nextString());
        tmp["paperCitations"]["ieee"].filter(p => (p["year"] == '2017' || p["year"] == '2018'))
        .map(p => parseInt(p["publicationNumber"])).forEach(n => {
            if(numbers.has(n)) {
                numbers.set(n, numbers.get(n) + 1);
            }
        })
    }
        journals.map(j => {
        return {
            "title": j["title"],
            "v": j["count"] != 0 ? numbers.get(j["number"])/j["count"]: 0
        }
    }).sort((p1, p2) => {
        if(p1["v"] == p2["v"]) {
            if(p1["title"] > p2["title"])
                return -1;
            else if(p1["title"] < p2["title"])
                return 1;
            return 0;
        }
        return p1["v"] - p2["v"];
    }).reverse().map(p => p["title"] + ": " + p["v"].toFixed(2)).forEach(s => console.log(s));
}

// default parsers for JS.
function nextInt() {
    return parseInt(nextString());
}

function nextFloat() {
    return parseFloat(nextString());
}

function nextString() {
    var next_string = "";
    clearWhitespaces();
    while (input_cursor < input_stdin.length && !isWhitespace(input_stdin[input_cursor])) {
        next_string += input_stdin[input_cursor];
        input_cursor += 1;
    }
    return next_string;
}

function nextChar() {
    clearWhitespaces();
    if (input_cursor < input_stdin.length) {
        return input_stdin[input_cursor++];
    } else {
        return '\0';
    }
}

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_cursor = 0;
process.stdin.on('data', function (data) { input_stdin += data; });
process.stdin.on('end', function () { main(); });

function isWhitespace(character) {
    return '\r\n'.indexOf(character) > -1;
}

function clearWhitespaces() {
    while (input_cursor < input_stdin.length && isWhitespace(input_stdin[input_cursor])) {
        // ignore the next whitespace character
        input_cursor += 1;
    }  
}