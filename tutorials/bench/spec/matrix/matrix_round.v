module matrix_round (
input wire [7:0] a,
input wire [7:0] b,
input wire [7:0] c_in,
output wire [7:0] c_out
);
assign c_out = c_in + a * b;
endmodule
