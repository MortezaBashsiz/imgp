#pragma once

static void help(char** argv) {
    cout << "Usage:\n"
         << argv[0] << "\n"
         << " [--width]\n"
            " [--height]\n"
            " [--camera]\n"
            " [--cascade]\n\n"
            "example:\n"
         << argv[0]
         << " --width=640 --height=480 --camera=0 --cascade=./file/face.xml\n";
}
