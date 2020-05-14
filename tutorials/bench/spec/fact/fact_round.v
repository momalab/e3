module fact_round (
input wire [7:0] n,
input wire [7:0] res_in,
input wire [7:0] i_in,
input wire [7:0] fact_in,
output wire [7:0] res_out,
output wire [7:0] i_out,
output wire [7:0] fact_out
);
assign fact_out = fact_in * i_in;
assign res_out = res_in + (i_in == n) * fact_in * i_in;
assign i_out = i_in + (i_in[0] + !i_in[0]);
endmodule
