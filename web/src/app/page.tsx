import Image from "next/image";

export default function Home() {
  return (
    <main className="flex-1">
      <section className="mx-auto flex min-h-screen max-w-3xl flex-col items-center justify-center px-6 text-center">
        <Image
          src="/hero.png"
          alt="K-A-D-E-R-S"
          className="mb-8 h-28 w-28 rounded-2xl object-cover shadow-sm"
          width={512}
          height={512}
        />

        <h1 className="font-mono text-5xl font-bold tracking-tight md:text-6xl">
          K-A-D-E-R-S
        </h1>

        <p className="mt-4 max-w-xl text-lg text-zinc-600 dark:text-zinc-400">
          Learning C++ one project at a time.
        </p>
      </section>
    </main>
  );
}