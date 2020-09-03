module speck_round (
input wire [7:0] x_in,
input wire [7:0] y_in,
input wire [7:0] k,
output wire [7:0] x_out,
output wire [7:0] y_out
);
assign x_out = (((x_in >> 7) | (x_in << 1)) + y_in) ^ k;
assign y_out =  ((y_in << 2) | (y_in >> 6)) ^ ((((x_in >> 7) | (x_in << 1)) + y_in) ^ k);
endmodule
