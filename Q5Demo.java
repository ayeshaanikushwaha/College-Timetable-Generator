// import java.util.*;

// class NumberBase {
//     private long value; // internal representation in base 10
//     private static final String SYMBOLS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

//     // Set number with a given base
//     public int setNumber(String stringNumber, int base) {
//         try {
//             value = convertToDecimal(stringNumber, base);
//             return 1; // success
//         } catch (Exception e) {
//             return -1; // invalid
//         }
//     }

//     // Get number in base b
//     public String getNumber(int base) {
//         if (base < 2 || base > SYMBOLS.length()) {
//             return "Invalid base";
//         }
//         return convertFromDecimal(value, base);
//     }

//     // Helper: convert string in base → decimal
//     private long convertToDecimal(String s, int base) {
//         long result = 0;
//         for (char c : s.toCharArray()) {
//             int digit = SYMBOLS.indexOf(c);
//             if (digit < 0 || digit >= base) {
//                 throw new IllegalArgumentException("Invalid digit " + c + " for base " + base);
//             }
//             result = result * base + digit;
//         }
//         return result;
//     }

//     // Helper: convert decimal → base string
//     private String convertFromDecimal(long num, int base) {
//         if (num == 0) return "0";
//         StringBuilder sb = new StringBuilder();
//         while (num > 0) {
//             sb.append(SYMBOLS.charAt((int)(num % base)));
//             num /= base;
//         }
//         return sb.reverse().toString();
//     }
// }

// // Derived class that allows custom symbol sets
// class NewSymbolNumber extends NumberBase {
//     private String customSymbols;

//     public NewSymbolNumber(String customSymbols) {
//         this.customSymbols = customSymbols;
//     }

//     // Override setNumber with custom symbols
//     public int setNumberCustom(String stringNumber, int base) {
//         try {
//             long val = 0;
//             for (char c : stringNumber.toCharArray()) {
//                 int digit = customSymbols.indexOf(c);
//                 if (digit < 0 || digit >= base) {
//                     throw new IllegalArgumentException("Invalid digit " + c + " for base " + base);
//                 }
//                 val = val * base + digit;
//             }
//             // store value internally
//             return super.setNumber(Long.toString(val), 10);
//         } catch (Exception e) {
//             return -1;
//         }
//     }

//     // Override getNumber with custom symbols
//     public String getNumberCustom(long value, int base) {
//         if (base < 2 || base > customSymbols.length()) {
//             return "Invalid base";
//         }
//         if (value == 0) return "" + customSymbols.charAt(0);
//         StringBuilder sb = new StringBuilder();
//         while (value > 0) {
//             sb.append(customSymbols.charAt((int)(value % base)));
//             value /= base;
//         }
//         return sb.reverse().toString();
//     }
// }

// public class Q5Demo {
//     public static void main(String[] args) {
//         NumberBase nb = new NumberBase();

//         // Example: setting number in base 16
//         if (nb.setNumber("1A", 16) == 1) {
//             System.out.println("Number in base 10: " + nb.getNumber(10));
//             System.out.println("Number in base 2: " + nb.getNumber(2));
//             System.out.println("Number in base 36: " + nb.getNumber(36));
//         } else {
//             System.out.println("Invalid number");
//         }

//         // Example with custom symbols
//         NewSymbolNumber customNb = new NewSymbolNumber("0123456789ABCDEF"); // hex
//         if (customNb.setNumberCustom("1A", 16) == 1) {
//             System.out.println("Custom number in base 16: " + customNb.getNumberCustom(26, 16));
//         }
//     }
// }
