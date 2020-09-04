module fib_round (
input wire [7:0] n,
input wire [7:0] res_in,
input wire [7:0] i_in,
input wire [7:0] fi_in,
input wire [7:0] f1_in,
output wire [7:0] res_out,
output wire [7:0] i_out,
output wire [7:0] fi_out,
output wire [7:0] f1_out
);
assign res_out = res_in + (i_in == n) * fi_in;
assign fi_out = f1_in + fi_in;
assign f1_out = fi_in;
assign i_out = i_in + (i_in[0] + !i_in[0]);
endmodule
