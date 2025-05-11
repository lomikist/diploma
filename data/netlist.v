// Netlist example for 4 cells (A through D)
// Format compatible with Yosys parsing

// Cell A module definition
module cellA (
    input wire clk,
    input wire reset,
    output wire out_B,
    output wire out_C, 
    output wire out_D,
    input wire [5:0] weight_B,
    input wire [5:0] weight_C,
    input wire [5:0] weight_D,
    output wire out
);
    // Internal implementation
    // (For a real netlist, this would contain the actual logic)
    assign out_B = reset ? 1'b0 : 1'b1;
    assign out_C = reset ? 1'b0 : 1'b1;
    assign out_D = reset ? 1'b0 : 1'b1;
    assign out = reset ? 1'b0 : 1'b1;
endmodule

// Cell B module definition
module cellB (
    input wire clk,
    input wire reset,
    input wire in_A,
    output wire out_C,
    output wire out_D,
    input wire [5:0] weight_A,
    input wire [5:0] weight_C,
    input wire [5:0] weight_D,
    output wire out
);
    // Internal implementation
    assign out_C = reset ? 1'b0 : in_A;
    assign out_D = reset ? 1'b0 : in_A;
    assign out = reset ? 1'b0 : in_A;
endmodule

// Cell C module definition
module cellC (
    input wire clk,
    input wire reset,
    input wire in_A,
    input wire in_B,
    output wire out_D,
    input wire [5:0] weight_A,
    input wire [5:0] weight_B,
    input wire [5:0] weight_D,
    output wire out
);
    // Internal implementation
    assign out_D = reset ? 1'b0 : (in_A | in_B);
    assign out = reset ? 1'b0 : (in_A | in_B);
endmodule

// Cell D module definition
module cellD (
    input wire clk,
    input wire reset,
    input wire in_A,
    input wire in_B,
    input wire in_C,
    input wire [5:0] weight_A,
    input wire [5:0] weight_B,
    input wire [5:0] weight_C,
    output wire out
);
    // Internal implementation
    assign out = reset ? 1'b0 : (in_A | in_B | in_C);
endmodule

// Top-level module
module top_module (
    input wire clk,
    input wire reset,
    output wire [3:0] out
);
    // Declare wires for interconnections between cells
    wire wire_A_B;  // Connection between cell A and B with weight 9
    wire wire_A_C;  // Connection between cell A and C with weight 12
    wire wire_A_D;  // Connection between cell A and D with weight 36
    wire wire_B_C;  // Connection between cell B and C with weight 44
    wire wire_B_D;  // Connection between cell B and D with weight 9
    wire wire_C_D;  // Connection between cell C and D with weight 7

    // Instantiate cells A, B, C, and D with their interconnections
    cellA cellA_inst (
        .clk(clk),
        .reset(reset),
        .out_B(wire_A_B), .weight_B(6'd9),
        .out_C(wire_A_C), .weight_C(6'd12),
        .out_D(wire_A_D), .weight_D(6'd36),
        .out(out[0])
    );

    cellB cellB_inst (
        .clk(clk),
        .reset(reset),
        .in_A(wire_A_B), .weight_A(6'd9),
        .out_C(wire_B_C), .weight_C(6'd44),
        .out_D(wire_B_D), .weight_D(6'd9),
        .out(out[1])
    );

    cellC cellC_inst (
        .clk(clk),
        .reset(reset),
        .in_A(wire_A_C), .weight_A(6'd12),
        .in_B(wire_B_C), .weight_B(6'd44),
        .out_D(wire_C_D), .weight_D(6'd7),
        .out(out[2])
    );

    cellD cellD_inst (
        .clk(clk),
        .reset(reset),
        .in_A(wire_A_D), .weight_A(6'd36),
        .in_B(wire_B_D), .weight_B(6'd9),
        .in_C(wire_C_D), .weight_C(6'd7),
        .out(out[3])
    );
endmodule
