#include "Harl.h"

int main() {
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("NONEXISTENT");  // This will not match any case

    return 0;
}
