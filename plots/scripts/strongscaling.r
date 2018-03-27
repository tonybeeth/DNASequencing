library(ggplot2)

data = read.csv("../strongscaling.csv")
str(data)

data$Fragments = as.factor(data$Fragments)

ggplot(data, aes(x = Processors, y = Time, color = Fragments)) + 
  geom_point(size=2) + geom_line(size = 1) + 
  scale_x_log10(breaks = c(128, 256, 512, 1024, 2048, 4096, 8192, 16384)) + 
  scale_y_continuous(breaks = c(seq(0, 1300, by=200))) + 
  xlab("Number of Cores") + 
  ylab("Execution Time (Seconds)") + 
  #ggtitle("  Strong Scaling on Randomly Generated DNA Fragments") +  
  theme_bw()