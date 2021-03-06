library(ggplot2)

data = read.csv("../weakscaling.csv")

ggplot(data, aes(x = Processors, y = Time)) + 
  geom_point(size=2, color="red") + geom_line(size = 1, color="red") + 
  #scale_fill_manual(breaks = c(64, 128, 256, 512, 1024, 2048, 4096, 8192), labels = c("64", "128", "256", "512", "1024", "2048", "4096", "8192")) + 
  scale_x_log10(breaks = c(1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192)) +#, labels = c("(64, 1)", "(128, 2)", "(256, 4)", "(512, 8)", "(1024, 16)", "(2048, 32)", "(4096, 64)", "(8192, 128)")) + 
  xlab("Cores") + 
  ylab("Execution Time (Seconds)") + 
  #ggtitle("                     Weak Scaling on Randomly Generated DNA Fragments") +  
  theme_bw()
