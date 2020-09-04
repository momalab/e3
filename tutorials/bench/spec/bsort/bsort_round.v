module bsort_round (
input wire [7:0] current_in,
input wire [7:0] next_in,
output wire [7:0] current_out,
output wire [7:0] next_out
);
assign current_out = (current_in <= next_in) ? current_in : next_in;
assign next_out    = (current_in <= next_in) ? next_in : current_in;
endmodule
