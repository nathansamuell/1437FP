#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants{
    // clear screen command (use "cls" on windows)
    inline const char *CLEAR_SCREEN = "clear";
    
    const std::string HEADER = 
        "·································································\n"
        ": ________   .---.       ,-----.    .-------.       ____        :\n"
        ":|        |  | ,_|     .'  .-,  '.  |  _ _   \\    .'  __ `.     :\n"
        ":|   .----',-./  )    / ,-.|  \\ _ \\ | ( ' )  |   /   '  \\  \\    :\n"
        ":|  _|____ \\  '_ '`) ;  \\  '_ /  | :|(_ o _) /   |___|  /  |    :\n"
        ":|_( )_   | > (_)  ) |  _`,/ \\ _/  || (_,_).' __    _.-`   |    :\n"
        ":(_ o._)__|(  .  .-' : (  '\\_/ \\   ;|  |\\ \\  |  |.'   _    |    :\n"
        ":|(_,_)     `-'`-'|___\\ `'/  \\  ) / |  | \\ `'   /|  _( )_  |    :\n"
        ":|   |       |        \'. \\_/``'.'  |  |  \\    / \\ (_ o _) /    :\n"
        ":'---'       `--------`  '-----'    ''-'   `'-'   '.(_,_).'     :\n"
        ": ________     ,-----.    .-------.      .-_'''-.       .-''-.  :\n"
        ":|        |  .'  .-,  '.  |  _ _   \\    '_( )_   \\    .'_ _   \\ :\n"
        ":|   .----' / ,-.|  \\ _ \\ | ( ' )  |   |(_ o _)|  '  / ( ` )   ':\n"
        ":|  _|____ ;  \\  '_ /  | :|(_ o _) /   . (_,_)/___| . (_ o _)  |:\n"
        ":|_( )_   ||  _`,/ \\ _/  || (_,_).' __ |  |  .-----.|  (_,_)___|:\n"
        ":(_ o._)__|: (  '\\_/ \\   ;|  |\\ \\  |  |'  \\  '-   .''  \\   .---.:\n"
        ":|(_,_)     \\ `'/  \\  ) / |  | \\ `'   / \\  `-'`   |  \\  `-'    /:\n"
        ":|   |       '. \\_/``'.'  |  |  \\    /   \\        /   \\       / :\n"
        ":'---'         '-----'    ''-'   `'-'     `'-...-'     `'-..-'  :\n"
        "·································································\n\n\n";

    // ANSI Color Escape Sequences
    const std::string RESET    = "\033[0m";
    
    // Text Colors
    const std::string BLACK    = "\033[30m";
    const std::string RED      = "\033[31m";
    const std::string GREEN    = "\033[32m";
    const std::string YELLOW   = "\033[33m";
    const std::string BLUE     = "\033[34m";
    const std::string MAGENTA  = "\033[35m";
    const std::string CYAN     = "\033[36m";
    const std::string WHITE    = "\033[37m";
    
    // Bright Text Colors
    const std::string BRIGHT_BLACK    = "\033[90m";
    const std::string BRIGHT_RED      = "\033[91m";
    const std::string BRIGHT_GREEN    = "\033[92m";
    const std::string BRIGHT_YELLOW   = "\033[93m";
    const std::string BRIGHT_BLUE     = "\033[94m";
    const std::string BRIGHT_MAGENTA  = "\033[95m";
    const std::string BRIGHT_CYAN     = "\033[96m";
    const std::string BRIGHT_WHITE    = "\033[97m";
    
    // Background Colors
    const std::string BG_BLACK    = "\033[40m";
    const std::string BG_RED      = "\033[41m";
    const std::string BG_GREEN    = "\033[42m";
    const std::string BG_YELLOW   = "\033[43m";
    const std::string BG_BLUE     = "\033[44m";
    const std::string BG_MAGENTA  = "\033[45m";
    const std::string BG_CYAN     = "\033[46m";
    const std::string BG_WHITE    = "\033[47m";
    
    // Bright Background Colors
    const std::string BG_BRIGHT_BLACK    = "\033[100m";
    const std::string BG_BRIGHT_RED      = "\033[101m";
    const std::string BG_BRIGHT_GREEN    = "\033[102m";
    const std::string BG_BRIGHT_YELLOW   = "\033[103m";
    const std::string BG_BRIGHT_BLUE     = "\033[104m";
    const std::string BG_BRIGHT_MAGENTA  = "\033[105m";
    const std::string BG_BRIGHT_CYAN     = "\033[106m";
    const std::string BG_BRIGHT_WHITE    = "\033[107m";
    
    // Text Styles
    const std::string BOLD       = "\033[1m";
    const std::string UNDERLINE  = "\033[4m";
    const std::string ITALIC     = "\033[3m";
    const std::string BLINK      = "\033[5m";
    
    // Browns and Earthy Tones (approximated)
    const std::string BROWN      = "\033[33m";      // Using yellow as a base
    const std::string DARK_BROWN = "\033[38;5;52m"; // Dark brown
}

#endif