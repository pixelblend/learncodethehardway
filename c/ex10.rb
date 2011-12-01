range = (0..10001)

puts %x{./ex10 #{range.collect{|r| "arg_"+r.to_s}.join(' ')}}
