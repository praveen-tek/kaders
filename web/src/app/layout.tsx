import type { Metadata } from "next";
import "./globals.css";
import { Noto_Sans, JetBrains_Mono } from "next/font/google";

const notoSans = Noto_Sans({
  subsets: ["latin"],
  variable: "--font-sans",
});

const jetbrainsMono = JetBrains_Mono({
  subsets: ["latin"],
  variable: "--font-mono",
});

export const metadata: Metadata = {
  title: {
    default: "K-A-D-E-R-S",
    template: "%s • K-A-D-E-R-S",
  },
  description:
    "Learning C++ one project at a time. A collection of experiments, terminal toys, and small projects built along the journey.",
  keywords: [
    "C++",
    "Programming",
    "Open Source",
    "Terminal",
    "Projects",
    "Learning",
  ],
  authors: [{ name: "Kader" }],
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html
      lang="en"
      className={`${notoSans.variable} ${jetbrainsMono.variable} h-full antialiased`}
    >
      <body className="min-h-full flex flex-col font-sans">
        {children}
      </body>
    </html>
  );
}