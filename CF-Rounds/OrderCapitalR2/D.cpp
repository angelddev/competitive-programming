#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Estados de DP: cantidad de substrings válidas hasta el índice i-1
    // o0: Impis (Odd) que terminan en 0
    // e0: Pares (Even) que terminan en 0
    // o1: Impis (Odd) que terminan en 1
    // e1: Pares (Even) que terminan en 1
    long long o0 = 0, e0 = 0, o1 = 0, e1 = 0;
    long long total_beautiful = 0;

    for (int i = 0; i < n; i++) {
        long long nxt_o0 = 0, nxt_e0 = 0, nxt_o1 = 0, nxt_e1 = 0;

        if (s[i] == '0') {
            // Extensiones que caen en O0 (e1 + '0') + Colapsos a O0 (e0 + '0') + Nuevo inicio ("0")
            nxt_o0 = e1 + e0 + 1;
            // Extensiones que caen en E0 (o1 + '0')
            nxt_e0 = o1;
            // Colapsos que caen en O1 (o0 + '0' se convierte en '1')
            nxt_o1 = o0;
            // Ninguna combinación con '0' puede terminar en un string par reducido que acabe en 1
            nxt_e1 = 0;

            // Las que colapsaron a longitud 1 más el nuevo inicio
            total_beautiful += (e0 + o0 + 1);
        } else {
            // Extensiones que caen en O1 (e0 + '1') + Colapsos a O1 (e1 + '1') + Nuevo inicio ("1")
            nxt_o1 = e0 + e1 + 1;
            // Extensiones que caen en E1 (o0 + '1')
            nxt_e1 = o0;
            // Colapsos que caen en O0 (o1 + '1' se convierte en '0')
            nxt_o0 = o1;
            // Ninguna combinación con '1' puede terminar en un string par reducido que acabe en 0
            nxt_e0 = 0;

            // Las que colapsaron a longitud 1 más el nuevo inicio
            total_beautiful += (e1 + o1 + 1);
        }

        // Actualizamos los estados de forma iterativa para el siguiente paso
        o0 = nxt_o0;
        e0 = nxt_e0;
        o1 = nxt_o1;
        e1 = nxt_e1;
    }

    cout << total_beautiful << "\n";
}

int main() {
    // Fast I/O indispensable para 10^6
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}